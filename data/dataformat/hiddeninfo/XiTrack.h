/*
 * XiTrack.h
 *
 *  Created on: 17 cze 2024
 *      Author: daniel
 */

#ifndef HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK_H_
#define HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK_H_

#include <Rtypes.h>
#include <RtypesCore.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TObject.h>

#include "Const.h"
#include "HiddenInfo.h"

namespace Hal {
  class Track;
  class V0Track;
  class XiTrack : public HiddenInfo {
    Int_t fTrackId           = {-1};
    Int_t fV0Id              = {-1};
    Int_t fChargedId         = {-1};
    Int_t fAssumedPdg        = {-1};
    Int_t fAssumedPdgNeu     = {-1};
    Int_t fAssumedPdgCharged = {-1};
    TVector3 fDcaNeu;  // DCA of neutral daughter
    TVector3 fDcaCharged;  // DCA of charged daughter
    TVector3 fMomNeu;  //momentum of neutral daughter
    TVector3 fMomCharged;
    Double_t fAlpha;
    Double_t fPtArm;
    TVector3 fDecay;
    Double_t fDecayLength;
    Double_t fCosAngle;
    Double_t fDauDist;

  public:
    XiTrack() {};
    /**
     * Set id of track in event
     * @param id
     */
    void SetTrackId(Int_t id) { fTrackId = id; }
    /**
     * Set id of V0 in event
     * @param neu
     */
    void SetV0Id(Int_t neu) { fV0Id = neu; }
    /**
     * Set id of charged daughter in event
     * @param id
     */
    void SetChId(Int_t id) { fChargedId = id; };
    /**
     * set distance between daughters at decay vertex
     * @param dauDist
     */
    void SetDauDist(Double_t dauDist) { fDauDist = dauDist; }

    void SetDecayPos(const TVector3& pos) { fDecay = pos; }
    void RotateZ(Double_t /*phi*/) {};  // TODO implement

    /**
     * Get id of track in event
     * @return track id
     */
    Int_t GetTrackId() const { return fTrackId; }
    /**
     * @return assumed PDG of this particle
     */
    inline Int_t GetPdg() const { return fAssumedPdg; };
    /**
     * @return assumed PDG of neutral daughter
     */
    inline Int_t GetPdgNeuDau() const { return fAssumedPdgNeu; };
    /**
     * @return assumed PDG of charged daughter
     */
    inline Int_t GetPdgChargedDau() const { return fAssumedPdgCharged; };
    /**
     * @return lenght of decay
     */
    Double_t GetDecayLength() const { return fDecayLength; }
    void SetDecLenght(Double_t len) { fDecayLength = len; }
    /**
     * Set assumed PDG of this particle
     * @param pid
     */
    inline void SetPdg(Int_t pid) { fAssumedPdg = pid; };
    /**
     * Set assumed PDG of neutral daughter
     * @param pid
     */
    inline void SetPdgNeuDau(Int_t pid) { fAssumedPdgNeu = pid; };
    /**
     * Set assumed PDG of charged daughter
     * @param pid
     */
    inline void SetPdgChargedDau(Int_t pid) { fAssumedPdgCharged = pid; };
    /**
     * Get id of Xi in event
     * @return id of Xi
     */
    Int_t GetV0Id() const { return fV0Id; }
    /**
     * Get id of charged daughter in event
     * @return id of charged daughter
     */
    Int_t GetChId() const { return fChargedId; }
    /**
     * copy content
     * @param v
     */
    virtual void CopyData(XiTrack* v);
    /**
     * set momentum of neutral daughter
     * 
     */
    void SetMomNeu(const TVector3& mom) { fMomNeu = mom; }
    /**
     * set momenum of neutral daugher
     * @param px
     * @param py
     * @param pz
     * @param m mass of neutral daughter
     */
    void SetMomNeu(Double_t px, Double_t py, Double_t pz){
      fMomNeu.SetXYZ(px, py, pz);
    }
    /**
     * set momentum of charged daughter
     * @param chargedDaughter
     */
    void SetMomCharged(const TVector3& mom) { fMomCharged = mom; }
    /**
     * set momenum of postive daugher
     * @param px
     * @param py
     * @param pz
     * @param m mass of positive daughter
     */
    void SetMomCharged(Double_t px, Double_t py, Double_t pz){
      fMomCharged.SetXYZ(px, py, pz);
    }

    TVector3 GetMomNeu() const { return fMomNeu; }
    TVector3 GetMomCharged() const { return fMomCharged; }
    void SetDcaNeu(const TVector3& dca) { fDcaNeu = dca; }
    void SetDcaCharged(const TVector3& dca) { fDcaCharged = dca; }
    TVector3 GetDcaNeu() const { return fDcaNeu; }
    TVector3 GetDcaCharged() const { return fDcaCharged; }
    void SetAlphaArm(Double_t alpha) { fAlpha = alpha; }
    Double_t GetAlphaArm() const { return fAlpha; }
    void SetPtArm(Double_t pt) { fPtArm = pt; }
    Double_t GetPtArm() const { return fPtArm; }

    void SetPdgDaughters(Int_t pdgNeu, Int_t pdgCharged) {
      fAssumedPdgNeu = pdgNeu;
      fAssumedPdgCharged = pdgCharged;
    }
    TVector3 Recalc(const Track& track);
    virtual ~XiTrack() {};
    ClassDef(XiTrack, 1)
  };

} /* namespace Hal */

#endif /* HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACK_H_ */
