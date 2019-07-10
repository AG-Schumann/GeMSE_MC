> Before
> After

276c276
<     G4double yPosCuPlateThick_mov       = -ySizeCuShielding/2.+ySizeCuPlateThick_mov/2.+0.001*cm;
---
>     G4double yPosCuPlateThick_mov       = -ySizeCuShielding/2.+ySizeCuPlateThick_mov/2.;


500,501c501,502
<       G4Box* innerPbShieldingTopMov_box = new G4Box("innerPbShieldingTopMov_box", xSizeInnerPbShieldingTop_mov/2.+0.001*cm, ySizeInnerPbShieldingTop_mov/2.+0.001*cm,zSizeInnerPbShieldingTop_mov/2.);
---
>       G4Box* innerPbShieldingTopMov_box = new G4Box("innerPbShieldingTopMov_box", xSizeInnerPbShieldingTop_mov/2., ySizeInnerPbShieldingTop_mov/2., zSizeInnerPbShieldingTop_mov/2.);


514,516c515,517
<       G4Box* outerPbShieldingHoleSideMov_box = new G4Box("outerPbShieldingHoleSideMov",xSizeInnerPbShieldingSide_mov/2.+0.005*cm,ySizeInnerPbShieldingSide_mov/2.+0.005*cm,zSizeInnerPbShieldingSide_mov/2.+0.005*cm);
<       G4Box* outerPbShieldingHoleBackMov_box = new G4Box("outerPbShieldingHoleSideMov_box",xSizeInnerPbShieldingBack_mov/2.+0.005*cm,ySizeInnerPbShieldingBack_mov/2.+0.005*cm,zSizeInnerPbShieldingBack_mov/2.+0.005*cm);
<       G4Box* outerPbShieldingHoleTopMov_box = new G4Box("outerPbShieldingHoleTopMov_box",xSizeInnerPbShieldingTop_mov/2.+0.005*cm,ySizeInnerPbShieldingTop_mov/2.+0.005*cm,(zSizeInnerPbShieldingTop_mov+zSizeCuPlateThick_mov-zSizeCuPlateThin_mov)/2.+0.005*cm);
---
>       G4Box* outerPbShieldingHoleSideMov_box = new G4Box("outerPbShieldingHoleSideMov",xSizeInnerPbShieldingSide_mov/2.,ySizeInnerPbShieldingSide_mov/2.,zSizeInnerPbShieldingSide_mov/2.);
>       G4Box* outerPbShieldingHoleBackMov_box = new G4Box("outerPbShieldingHoleSideMov_box",xSizeInnerPbShieldingBack_mov/2.,ySizeInnerPbShieldingBack_mov/2., zSizeInnerPbShieldingBack_mov/2.);
>       G4Box* outerPbShieldingHoleTopMov_box = new G4Box("outerPbShieldingHoleTopMov_box",xSizeInnerPbShieldingTop_mov/2.,ySizeInnerPbShieldingTop_mov/2.,(zSizeInnerPbShieldingTop_mov+zSizeCuPlateThick_mov-zSizeCuPlateThin_mov)/2);


571,572c572,573
<   G4UnionSolid* CuHsg_uni2	= new G4UnionSolid("CuHsg_uni2",CuHsg_uni1,CuHsg_bottom_uni2,0,G4ThreeVector(0.,0.,-heightCuHsg+heightEndcap/2.-heightCuHsg_bottom/2.+0.005*cm));
---
>   G4UnionSolid* CuHsg_uni2	= new G4UnionSolid ("CuHsg_uni2",CuHsg_uni1,CuHsg_bottom_uni2,0,G4ThreeVector(0.,0.,-heightCuHsg+heightEndcap/2.-heightCuHsg_bottom/2.));
