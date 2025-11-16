/**
 * @file XiTrackBase.cpp
 * @author wojciechbojakowski
 * @date 2.11.2025
 */
#include "XiTrackBase.h"
#include "ExpEvent.h"
#include "Track.h"

void XiTrackBase::CopyData(XiTrackBase* v){
    fTrackId     = v->fTrackId;
    fAssumedPdg  = v->fAssumedPdg;
    fDecay       = v->fDecay;
    fDecayLength = v->fDecayLength;
    fCosAngle    = v->fCosAngle;
}