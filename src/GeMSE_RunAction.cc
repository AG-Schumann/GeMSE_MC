// Make this appear first!
#include "G4Timer.hh"

#include "GeMSE_RunAction.hh"
#include "GeMSE_Analysis.hh"
#include "GeMSE_RunMessenger.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "TTree.h"
#include <sys/time.h>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GeMSE_RunAction::GeMSE_RunAction(TTree* tree)
{
    ftree = tree;
    timer = new G4Timer;
    
    // create run analysis
    fRunAnalysis = new GeMSE_Analysis();
    
    //create a messenger for this class
    runMessenger = new GeMSE_RunMessenger(fRunAnalysis);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GeMSE_RunAction::~GeMSE_RunAction()
{
    delete timer;
    //delete fRunAnalysis;
    delete runMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GeMSE_RunAction::BeginOfRunAction(const G4Run* aRun)
{
    
	CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
	struct timeval hTimeValue;
	gettimeofday(&hTimeValue, NULL);
	aSeed=hTimeValue.tv_usec;
	//aSeed=(G4long)time(NULL)+(G4long)getpid();
	//aSeed=(G4long)getrandom()+(G4long)time(NULL);
	CLHEP::HepRandom::setTheSeed(aSeed);
	G4cout << "Setting the seed for this run to " << aSeed << G4endl;

    G4int RunID = aRun->GetRunID();
    
    G4int NEvents = aRun->GetNumberOfEventToBeProcessed();
    
    // set Nb of events
    fRunAnalysis->SetNEvents(NEvents);
    
    G4cout << "### Run " << RunID << " started with " << NEvents << " events." << G4endl;
    timer->Start();
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GeMSE_RunAction::EndOfRunAction(const G4Run* aRun)
{
    // if a tree is defined
    if (ftree) {
        
        // calculate efficiencies
        fRunAnalysis->CalcEfficiencies();
        
        // fill ROOT Tree
        G4double energy, efficiency, efficiency_err, eff_BR;
        ftree->Branch("energy",&energy);
        ftree->Branch("efficiency",&efficiency);
        ftree->Branch("efficiency_err",&efficiency_err);
        ftree->Branch("eff_BR",&eff_BR);
        int nlines = fRunAnalysis->GetNLines();
        for (int i=0; i<nlines; ++i) {
            energy = fRunAnalysis->GetEnergy(i);
            efficiency = fRunAnalysis->GetEfficiency(i);
            efficiency_err = fRunAnalysis->GetEfficiency_err(i);
            eff_BR = fRunAnalysis->GetEffBR(i);
            
            ftree->Fill();
        }
        
        // clear data
        fRunAnalysis->Clear();
    }
        
    timer->Stop();
    
    G4cout << "\n" << "### Finished ###" << G4endl;
    G4cout << "Runtime: " << *timer << G4endl;   
      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
