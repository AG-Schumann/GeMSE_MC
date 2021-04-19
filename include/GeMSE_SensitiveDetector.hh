#ifndef GeMSE_SensitiveDetector_h
#define GeMSE_SensitiveDetector_h 1

#include "GeMSE_Hit.hh"

#include <TH1D.h>

#include "G4VSensitiveDetector.hh"

class G4Step;
class G4HCofThisEvent;

class GeMSE_SensitiveDetector : public G4VSensitiveDetector
{
  public:
	GeMSE_SensitiveDetector(G4String);
	~GeMSE_SensitiveDetector();

	//! create an instance of GeMSE_HitsCollection and add a new hits collection
	//! to the G4HCofThisEvent instance
	void Initialize(G4HCofThisEvent*);

	G4bool ProcessHits(G4Step*, G4TouchableHistory*);

	void EndOfEvent(G4HCofThisEvent*);


  private:
	GeMSE_HitsCollection* HitsCollection;
    int HCID;
    TH1D* fhTotEdep;


};

#endif
