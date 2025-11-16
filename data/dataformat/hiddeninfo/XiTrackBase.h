/*
 * XiTrackBase.h
 *
 *  Created on: 2.11.2025
 *  Author: wojciechbojakowski
 * 
 *  Virtual base class for XiTrack and XiTrack3Particle
 * 
 */
#ifndef HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACKBASE_H_
#define HAL_DATA_DATAFORMAT_HIDDENINFO_XITRACKBASE_H_

#include <Rtypes.h>
#include <RtypesCore.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TObject.h>

#include "Const.h"
#include "HiddenInfo.h"

class XiTrackBase : public HiddenInfo {
protected:
    Int_t fTrackId        = -1;
    Int_t fAssumedPdg     = -1;
    TVector3 fDecay;
    Double_t fDecayLength = 0.0;
    Double_t fCosAngle    = 0.0;

public:
    XiTrackBase() {};
    virtual ~XiTrackBase() {};

    /**
     * Set id of track in event
     * @param id
     */
    void SetTrackId(Int_t id) { fTrackId = id; }
    /**
     * Set decay position
     * @param pos
     */
    void SetDecayPos(const TVector3& pos) { fDecay = pos; }
    /**
     * Set decay position
     * @param x
     * @param y
     * @param z
     */
    void SetDecayPos(Double_t x, Double_t y, Double_t z) { fDecay.SetXYZ(x, y, z); }
    /**
     * Set decay length
     * @param length
     */
    void SetDecayLength(Double_t length) { fDecayLength = length; }
    /**
     * Set cosine of pointing angle
     * @param cosAngle
     */
    void SetCosAngle(Double_t cosAngle) { fCosAngle = cosAngle; }
    /**
     * Set assumed PDG of this particle
     * @param pdg
     */
    void SetPdg(Int_t pdg) { fAssumedPdg = pdg; }

    /**
     * Get id of track in event
     * @return track id
     */
    Int_t GetTrackId() const { return fTrackId; }
    /**
     * Get assumed PDG of this particle
     * @return assumed PDG
     */
    Int_t GetPdg() const { return fAssumedPdg; }
    /**
     * Get decay position
     * @return decay position
     */
    TVector3 GetDecay() const { return fDecay; }
    /**
     * Get decay length
     * @return decay length
     */
    Double_t GetDecayLength() const { return fDecayLength; }
    /**
     * Get cosine of pointing angle
     * @return cosine of pointing angle
     */
    Double_t GetCosAngle() const { return fCosAngle; }

    virtual void CopyData(XiTrack3Particle* v);

    ClassDef(XiTrack3Particle, 1);
};