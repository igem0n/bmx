/*
 * ARRI RDD 55 §6.2.4.6 — ColorProcessing Set
 *
 * Copyright (C) 2025, ARRI RDD 54/55 metadata support
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <memory>

#include <libMXF++/MXF.h>

#include <mxf/mxf_arri.h>

using namespace std;
using namespace mxfpp;


const mxfKey ARRIColorProcessingBase::setKey = MXF_SET_K(ColorProcessing);


ARRIColorProcessingBase::ARRIColorProcessingBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ARRIColorProcessingBase::ARRIColorProcessingBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

ARRIColorProcessingBase::~ARRIColorProcessingBase()
{}


bool ARRIColorProcessingBase::getWhiteBalanceApplied() const
{
    return getBooleanItem(&MXF_ITEM_K(ColorProcessing, WhiteBalanceApplied));
}

MetadataSet* ARRIColorProcessingBase::getSceneColorEncoding() const
{
    return getStrongRefItem(&MXF_ITEM_K(ColorProcessing, SceneColorEncoding));
}

bool ARRIColorProcessingBase::haveColorLookApplied() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, ColorLookApplied));
}

bool ARRIColorProcessingBase::getColorLookApplied() const
{
    return getBooleanItem(&MXF_ITEM_K(ColorProcessing, ColorLookApplied));
}

bool ARRIColorProcessingBase::haveLUT3Ds() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, LUT3Ds));
}

vector<MetadataSet*> ARRIColorProcessingBase::getLUT3Ds() const
{
    vector<MetadataSet*> result;
    unique_ptr<ObjectIterator> iter(getStrongRefArrayItem(&MXF_ITEM_K(ColorProcessing, LUT3Ds)));
    while (iter->next())
        result.push_back(iter->get());
    return result;
}

bool ARRIColorProcessingBase::haveLookModified() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, LookModified));
}

bool ARRIColorProcessingBase::getLookModified() const
{
    return getBooleanItem(&MXF_ITEM_K(ColorProcessing, LookModified));
}

bool ARRIColorProcessingBase::haveCDLSlope() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, CDLSlope));
}

vector<float> ARRIColorProcessingBase::getCDLSlope() const
{
    return getFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLSlope));
}

bool ARRIColorProcessingBase::haveCDLOffset() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, CDLOffset));
}

vector<float> ARRIColorProcessingBase::getCDLOffset() const
{
    return getFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLOffset));
}

bool ARRIColorProcessingBase::haveCDLPower() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, CDLPower));
}

vector<float> ARRIColorProcessingBase::getCDLPower() const
{
    return getFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLPower));
}

bool ARRIColorProcessingBase::haveCDLSaturation() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, CDLSaturation));
}

float ARRIColorProcessingBase::getCDLSaturation() const
{
    return getFloatItem(&MXF_ITEM_K(ColorProcessing, CDLSaturation));
}

bool ARRIColorProcessingBase::haveLookIntensity() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, LookIntensity));
}

float ARRIColorProcessingBase::getLookIntensity() const
{
    return getFloatItem(&MXF_ITEM_K(ColorProcessing, LookIntensity));
}

bool ARRIColorProcessingBase::haveLookFileName() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, LookFileName));
}

string ARRIColorProcessingBase::getLookFileName() const
{
    return getStringItem(&MXF_ITEM_K(ColorProcessing, LookFileName));
}

bool ARRIColorProcessingBase::haveLookNote() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, LookNote));
}

string ARRIColorProcessingBase::getLookNote() const
{
    return getStringItem(&MXF_ITEM_K(ColorProcessing, LookNote));
}

bool ARRIColorProcessingBase::haveVideoRenderingVersion() const
{
    return haveItem(&MXF_ITEM_K(ColorProcessing, VideoRenderingVersion));
}

string ARRIColorProcessingBase::getVideoRenderingVersion() const
{
    return getStringItem(&MXF_ITEM_K(ColorProcessing, VideoRenderingVersion));
}


void ARRIColorProcessingBase::setWhiteBalanceApplied(bool value)
{
    setBooleanItem(&MXF_ITEM_K(ColorProcessing, WhiteBalanceApplied), value);
}

void ARRIColorProcessingBase::setSceneColorEncoding(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(ColorProcessing, SceneColorEncoding), value);
}

void ARRIColorProcessingBase::setColorLookApplied(bool value)
{
    setBooleanItem(&MXF_ITEM_K(ColorProcessing, ColorLookApplied), value);
}

void ARRIColorProcessingBase::setLUT3Ds(const vector<MetadataSet*> &value)
{
    WrapObjectVectorIterator<MetadataSet> iter(value);
    setStrongRefArrayItem(&MXF_ITEM_K(ColorProcessing, LUT3Ds), &iter);
}

void ARRIColorProcessingBase::setLookModified(bool value)
{
    setBooleanItem(&MXF_ITEM_K(ColorProcessing, LookModified), value);
}

void ARRIColorProcessingBase::setCDLSlope(const vector<float> &value)
{
    setFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLSlope), value);
}

void ARRIColorProcessingBase::setCDLOffset(const vector<float> &value)
{
    setFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLOffset), value);
}

void ARRIColorProcessingBase::setCDLPower(const vector<float> &value)
{
    setFloatArrayItem(&MXF_ITEM_K(ColorProcessing, CDLPower), value);
}

void ARRIColorProcessingBase::setCDLSaturation(float value)
{
    setFloatItem(&MXF_ITEM_K(ColorProcessing, CDLSaturation), value);
}

void ARRIColorProcessingBase::setLookIntensity(float value)
{
    setFloatItem(&MXF_ITEM_K(ColorProcessing, LookIntensity), value);
}

void ARRIColorProcessingBase::setLookFileName(string value)
{
    setStringItem(&MXF_ITEM_K(ColorProcessing, LookFileName), value);
}

void ARRIColorProcessingBase::setLookNote(string value)
{
    setStringItem(&MXF_ITEM_K(ColorProcessing, LookNote), value);
}

void ARRIColorProcessingBase::setVideoRenderingVersion(string value)
{
    setStringItem(&MXF_ITEM_K(ColorProcessing, VideoRenderingVersion), value);
}
