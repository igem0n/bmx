/*
 * ARRI RDD 55 §6.2.4.3 — SensorCharacteristics Set
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


const mxfKey ARRISensorCharacteristicsBase::setKey = MXF_SET_K(SensorCharacteristics);


ARRISensorCharacteristicsBase::ARRISensorCharacteristicsBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ARRISensorCharacteristicsBase::ARRISensorCharacteristicsBase(
    HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

ARRISensorCharacteristicsBase::~ARRISensorCharacteristicsBase()
{}


string ARRISensorCharacteristicsBase::getSensorName() const
{
    return getStringItem(&MXF_ITEM_K(SensorCharacteristics, SensorName));
}

float ARRISensorCharacteristicsBase::getSensorPixelPitch() const
{
    return getFloatItem(&MXF_ITEM_K(SensorCharacteristics, SensorPixelPitch));
}

MetadataSet* ARRISensorCharacteristicsBase::getOverallSensorDimensions() const
{
    return getStrongRefItem(&MXF_ITEM_K(SensorCharacteristics, OverallSensorDimensions));
}

MetadataSet* ARRISensorCharacteristicsBase::getSensorAcquisitionRectangle() const
{
    return getStrongRefItem(&MXF_ITEM_K(SensorCharacteristics, SensorAcquisitionRectangle));
}

bool ARRISensorCharacteristicsBase::getSensorUserPixelMaskActive() const
{
    return getBooleanItem(&MXF_ITEM_K(SensorCharacteristics, SensorUserPixelMaskActive));
}

bool ARRISensorCharacteristicsBase::haveSensorUserPixelMaskData() const
{
    return haveItem(&MXF_ITEM_K(SensorCharacteristics, SensorUserPixelMaskData));
}

ByteArray ARRISensorCharacteristicsBase::getSensorUserPixelMaskData() const
{
    return getRawBytesItem(&MXF_ITEM_K(SensorCharacteristics, SensorUserPixelMaskData));
}


void ARRISensorCharacteristicsBase::setSensorName(string value)
{
    setStringItem(&MXF_ITEM_K(SensorCharacteristics, SensorName), value);
}

void ARRISensorCharacteristicsBase::setSensorPixelPitch(float value)
{
    setFloatItem(&MXF_ITEM_K(SensorCharacteristics, SensorPixelPitch), value);
}

void ARRISensorCharacteristicsBase::setOverallSensorDimensions(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(SensorCharacteristics, OverallSensorDimensions), value);
}

void ARRISensorCharacteristicsBase::setSensorAcquisitionRectangle(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(SensorCharacteristics, SensorAcquisitionRectangle), value);
}

void ARRISensorCharacteristicsBase::setSensorUserPixelMaskActive(bool value)
{
    setBooleanItem(&MXF_ITEM_K(SensorCharacteristics, SensorUserPixelMaskActive), value);
}

void ARRISensorCharacteristicsBase::setSensorUserPixelMaskData(ByteArray value)
{
    setRawBytesItem(&MXF_ITEM_K(SensorCharacteristics, SensorUserPixelMaskData), value);
}
