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

#ifndef MXFPP_ARRI_LUT3D_BASE_H_
#define MXFPP_ARRI_LUT3D_BASE_H_

#include <libMXF++/metadata/InterchangeObject.h>

namespace mxfpp
{

class ARRILUT3DBase : public InterchangeObject
{
public:
    friend class MetadataSetFactory<ARRILUT3DBase>;
    static const mxfKey setKey;

public:
    ARRILUT3DBase(HeaderMetadata *headerMetadata);
    virtual ~ARRILUT3DBase();

    // getters
    uint32_t getLUT3DScalingFactor() const;
    float getLUT3DNormalizationGain() const;
    float getLUT3DNormalizationOffset() const;
    uint16_t getLUT3DMeshPointsPerChannel() const;
    ByteArray getLUT3DData() const;
    mxfAUID getLUT3DDataLayout() const;
    MetadataSet* getLUT3DSourceColorEncoding() const;
    MetadataSet* getLUT3DTargetColorEncoding() const;
    bool haveLUT3DIdentifier() const;
    std::string getLUT3DIdentifier() const;

    // setters
    void setLUT3DScalingFactor(uint32_t value);
    void setLUT3DNormalizationGain(float value);
    void setLUT3DNormalizationOffset(float value);
    void setLUT3DMeshPointsPerChannel(uint16_t value);
    void setLUT3DData(ByteArray value);
    void setLUT3DDataLayout(mxfAUID value);
    void setLUT3DSourceColorEncoding(MetadataSet *value);
    void setLUT3DTargetColorEncoding(MetadataSet *value);
    void setLUT3DIdentifier(std::string value);

protected:
    ARRILUT3DBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
