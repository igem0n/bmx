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

#ifndef MXFPP_ARRI_SENSOR_CHARACTERISTICS_BASE_H_
#define MXFPP_ARRI_SENSOR_CHARACTERISTICS_BASE_H_

#include <libMXF++/metadata/InterchangeObject.h>

namespace mxfpp
{

class ARRISensorCharacteristicsBase : public InterchangeObject
{
public:
    friend class MetadataSetFactory<ARRISensorCharacteristicsBase>;
    static const mxfKey setKey;

public:
    ARRISensorCharacteristicsBase(HeaderMetadata *headerMetadata);
    virtual ~ARRISensorCharacteristicsBase();

    // getters
    std::string getSensorName() const;
    float getSensorPixelPitch() const;
    MetadataSet* getOverallSensorDimensions() const;
    MetadataSet* getSensorAcquisitionRectangle() const;
    bool getSensorUserPixelMaskActive() const;
    bool haveSensorUserPixelMaskData() const;
    ByteArray getSensorUserPixelMaskData() const;

    // setters
    void setSensorName(std::string value);
    void setSensorPixelPitch(float value);
    void setOverallSensorDimensions(MetadataSet *value);
    void setSensorAcquisitionRectangle(MetadataSet *value);
    void setSensorUserPixelMaskActive(bool value);
    void setSensorUserPixelMaskData(ByteArray value);

protected:
    ARRISensorCharacteristicsBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
