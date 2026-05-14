/*
 * ARRI RDD 55 §6.2.3.2 — TextureGen1ProcessingSubDescriptor
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

#ifndef MXFPP_TEXTURE_GEN1_PROCESSING_SUBDESCRIPTOR_BASE_H_
#define MXFPP_TEXTURE_GEN1_PROCESSING_SUBDESCRIPTOR_BASE_H_

#include <libMXF++/metadata/base/TextureProcessingSubDescriptorBase.h>

namespace mxfpp
{

class TextureGen1ProcessingSubDescriptorBase : public TextureProcessingSubDescriptorBase
{
public:
    friend class MetadataSetFactory<TextureGen1ProcessingSubDescriptorBase>;
    static const mxfKey setKey;

public:
    TextureGen1ProcessingSubDescriptorBase(HeaderMetadata *headerMetadata);
    virtual ~TextureGen1ProcessingSubDescriptorBase();

    // getters
    uint8_t getTextureNoiseReductionMode() const;
    float getTextureImageSharpness() const;
    float getTextureImageDetail() const;
    bool haveTextureNoiseReductionStrength() const;
    float getTextureNoiseReductionStrength() const;

    // setters
    void setTextureNoiseReductionMode(uint8_t value);
    void setTextureImageSharpness(float value);
    void setTextureImageDetail(float value);
    void setTextureNoiseReductionStrength(float value);

protected:
    TextureGen1ProcessingSubDescriptorBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
