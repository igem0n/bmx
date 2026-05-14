/*
 * ARRI RDD 55 §6.2.4.5 — LUT3D Set
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

#include <libMXF++/MXF.h>

#include <mxf/mxf_arri.h>

using namespace std;
using namespace mxfpp;


const mxfKey ARRILUT3DBase::setKey = MXF_SET_K(LUT3D);


ARRILUT3DBase::ARRILUT3DBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ARRILUT3DBase::ARRILUT3DBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

ARRILUT3DBase::~ARRILUT3DBase()
{}


uint32_t ARRILUT3DBase::getLUT3DScalingFactor() const
{
    return getUInt32Item(&MXF_ITEM_K(LUT3D, LUT3DScalingFactor));
}

float ARRILUT3DBase::getLUT3DNormalizationGain() const
{
    return getFloatItem(&MXF_ITEM_K(LUT3D, LUT3DNormalizationGain));
}

float ARRILUT3DBase::getLUT3DNormalizationOffset() const
{
    return getFloatItem(&MXF_ITEM_K(LUT3D, LUT3DNormalizationOffset));
}

uint16_t ARRILUT3DBase::getLUT3DMeshPointsPerChannel() const
{
    return getUInt16Item(&MXF_ITEM_K(LUT3D, LUT3DMeshPointsPerChannel));
}

ByteArray ARRILUT3DBase::getLUT3DData() const
{
    return getRawBytesItem(&MXF_ITEM_K(LUT3D, LUT3DData));
}

mxfAUID ARRILUT3DBase::getLUT3DDataLayout() const
{
    return getAUIDItem(&MXF_ITEM_K(LUT3D, LUT3DDataLayout));
}

MetadataSet* ARRILUT3DBase::getLUT3DSourceColorEncoding() const
{
    return getStrongRefItem(&MXF_ITEM_K(LUT3D, LUT3DSourceColorEncoding));
}

MetadataSet* ARRILUT3DBase::getLUT3DTargetColorEncoding() const
{
    return getStrongRefItem(&MXF_ITEM_K(LUT3D, LUT3DTargetColorEncoding));
}

bool ARRILUT3DBase::haveLUT3DIdentifier() const
{
    return haveItem(&MXF_ITEM_K(LUT3D, LUT3DIdentifier));
}

string ARRILUT3DBase::getLUT3DIdentifier() const
{
    return getStringItem(&MXF_ITEM_K(LUT3D, LUT3DIdentifier));
}


void ARRILUT3DBase::setLUT3DScalingFactor(uint32_t value)
{
    setUInt32Item(&MXF_ITEM_K(LUT3D, LUT3DScalingFactor), value);
}

void ARRILUT3DBase::setLUT3DNormalizationGain(float value)
{
    setFloatItem(&MXF_ITEM_K(LUT3D, LUT3DNormalizationGain), value);
}

void ARRILUT3DBase::setLUT3DNormalizationOffset(float value)
{
    setFloatItem(&MXF_ITEM_K(LUT3D, LUT3DNormalizationOffset), value);
}

void ARRILUT3DBase::setLUT3DMeshPointsPerChannel(uint16_t value)
{
    setUInt16Item(&MXF_ITEM_K(LUT3D, LUT3DMeshPointsPerChannel), value);
}

void ARRILUT3DBase::setLUT3DData(ByteArray value)
{
    setRawBytesItem(&MXF_ITEM_K(LUT3D, LUT3DData), value);
}

void ARRILUT3DBase::setLUT3DDataLayout(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(LUT3D, LUT3DDataLayout), value);
}

void ARRILUT3DBase::setLUT3DSourceColorEncoding(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(LUT3D, LUT3DSourceColorEncoding), value);
}

void ARRILUT3DBase::setLUT3DTargetColorEncoding(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(LUT3D, LUT3DTargetColorEncoding), value);
}

void ARRILUT3DBase::setLUT3DIdentifier(string value)
{
    setStringItem(&MXF_ITEM_K(LUT3D, LUT3DIdentifier), value);
}
