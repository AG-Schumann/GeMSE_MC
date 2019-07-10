#ifndef GeMSE_RunAction_h
#define GeMSE_RunAction_h 1

#include "globals.hh"
#include "G4UserRunAction.hh"
#include "G4ThreeVector.hh"

#include "GeMSE_Analysis.hh"

#include "TTree.h"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Timer;
class G4Run;
class GeMSE_RunMessenger;

class GeMSE_RunAction : public G4UserRunAction
{
  public:
    GeMSE_RunAction(TTree* tree);
   ~GeMSE_RunAction();

  public:
    void BeginOfRunAction(const G4Run* aRun);
    void EndOfRunAction(const G4Run* aRun);

    GeMSE_Analysis* GetRunAnalysis() { return fRunAnalysis; };


  private:
    G4Timer* timer;

	TTree* ftree;

	G4long aSeed;
    GeMSE_Analysis* fRunAnalysis;
    GeMSE_RunMessenger* runMessenger;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*GeMSE_RunAction_h*/
