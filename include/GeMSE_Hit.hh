#ifndef GeMSE_Hit_h
#define GeMSE_Hit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class GeMSE_Hit : public G4VHit
{

public:

      GeMSE_Hit();
     ~GeMSE_Hit();
      GeMSE_Hit(const GeMSE_Hit&);
      const GeMSE_Hit& operator=(const GeMSE_Hit&);
      G4int operator==(const GeMSE_Hit&) const;

      inline void* operator new(size_t);
      inline void  operator delete(void*);

      void Draw();
      void Print();

public:

	void SetEdep(G4double de)				{ edep = de; };

	G4double GetEdep()				{ return edep; };

private:
	G4double		edep;

};


typedef G4THitsCollection <GeMSE_Hit> GeMSE_HitsCollection;

extern G4Allocator<GeMSE_Hit> GeMSE_HitAllocator;


inline void* GeMSE_Hit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) GeMSE_HitAllocator.MallocSingle();
  return aHit;
}


inline void GeMSE_Hit::operator delete(void *aHit)
{
  GeMSE_HitAllocator.FreeSingle((GeMSE_Hit*) aHit);
}


#endif
