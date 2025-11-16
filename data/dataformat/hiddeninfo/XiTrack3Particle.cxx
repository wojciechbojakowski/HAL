/*
 * XiTrack.cpp
 *
 *  Created on: 17 cze 2024
 *      Author: daniel
 *      Moddified by Wojciech Bojakowski in 2025:
 */

#include "XiTrack3Particle.h"
#include "V0Track.h"
#include "ExpEvent.h"
#include "Track.h"

namespace Hal {

  void XiTrack3Particle::CopyData(XiTrack3Particle* v) {
    XiTrackBase::CopyData(v);
    daughter1_id = v->daughter1_id;
    daughter2_id = v->daughter2_id;
    daughter3_id = v->daughter3_id;
    // fTrackId     = v->fTrackId;
    // fAssumedPdg  = v->fAssumedPdg;
    // fDecay       = v->fDecay;
    // fDecayLength = v->fDecayLength;
    // fCosAngle    = v->fCosAngle;

  }

//   TVector3 XiTrack::Recalc(const Track& track) {
//     const TVector3 Mom(track.GetPx(), track.GetPy(), track.GetPz());

//     Double_t Ptot          = Mom.Mag();
//     Double_t pPosTot       = fMomCharged.Mag();
//     Double_t MomPosAlongV0 = fMomCharged * Mom / Ptot;
//     Double_t MomNegALongV0 = fMomNeu * Mom / Ptot;

//     SetAlphaArm((MomPosAlongV0 - MomNegALongV0) / (MomPosAlongV0 + MomNegALongV0));
//     SetPtArm(TMath::Sqrt(pPosTot * pPosTot - MomPosAlongV0 * MomPosAlongV0));
//     TVector3 vertex = track.GetEvent()->GetVertex()->Vect();
//     TVector3 pozV0  = fDecay - vertex;

//     Double_t t = -(pozV0 * Mom) / (Ptot * Ptot);
//     TVector3 dca;
//     dca.SetXYZ(pozV0.X() + t * Mom.X(), pozV0.Y() + t * Mom.Y(), pozV0.Z() + t * Mom.Z());
//     TVector3 dca_rel = dca - pozV0;
//     fCosAngle        = pozV0 * Mom / (Ptot * pozV0.Mag());
//     SetDecLenght(dca_rel.Mag());
//     return dca;
//   }

  // void XiTrack::SetMomCharged(Double_t px, Double_t py, Double_t pz) {
  //   fMomCharged.SetXYZ(px, py, pz);
  // }
  // void XiTrack::SetMomNeu(Double_t px, Double_t py, Double_t pz) {
  //   fMomNeu.SetXYZ(px, py, pz);
  // }
}  // namespace Hal
