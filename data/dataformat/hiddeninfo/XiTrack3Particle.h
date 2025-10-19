/*
 * XiTrack.h
 *
 *  Created on: 17 cze 2024
 *      Author: daniel
 */

#ifndef HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK3PARTICLE_H_
#define HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK3PARTICLE_H_

#include <Rtypes.h>
#include <RtypesCore.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TObject.h>

#include "Const.h"
#include "HiddenInfo.h"

namespace Hal {
  //class Track;
  class XiTrack3Particle : public HiddenInfo{
    Int_t fTrackId           = {-1};//to
    Int_t fAssumedPdg        = {-1};//to
    TVector3 fDecay;//to
    Double_t fDecayLength;
    Double_t fCosAngle;//to
    Int_t daughter1_id = {-1};                                                         
    Int_t daughter2_id = {-1};                                                         
    Int_t daughter3_id = {-1};                                                          
    
    public:
    XiTrack3Particle() {};
    virtual ~XiTrack3Particle() {};
    void SetTrackId(Int_t id) { fTrackId = id; }
    void SetDaughter1Id(Int_t id) { daughter1_id = id; }
    void SetDaughter2Id(Int_t id) { daughter2_id = id; }
    void SetDaughter3Id(Int_t id) { daughter3_id = id; }
    void SetPdg(Int_t pdg) { fAssumedPdg = pdg; }
    void SetDecay(const TVector3& decay) { fDecay = decay; }
    void SetDecayLength(Double_t length) { fDecayLength = length; }
    void SetCosAngle(Double_t cosAngle) { fCosAngle = cosAngle; }
    Int_t GetTrackId() const { return fTrackId; }
    Int_t GetDaughter1Id() const { return daughter1_id; }
    Int_t GetDaughter2Id() const { return daughter2_id; }
    Int_t GetDaughter3Id() const { return daughter3_id; }
    Int_t GetPdg() const { return fAssumedPdg; }
    TVector3 GetDecay() const { return fDecay; }
    Double_t GetDecayLength() const { return fDecayLength; }
    Double_t GetCosAngle() const { return fCosAngle; }
    virtual void CopyData(XiTrack* v);
    ClassDef(XiTrack, 1)
  };

} /* namespace Hal */

#endif /* HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK3PARTICLE_H_ */