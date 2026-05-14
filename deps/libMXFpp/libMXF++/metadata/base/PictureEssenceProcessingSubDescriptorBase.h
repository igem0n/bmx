/*
 * ARRI RDD 55 §6.2.2 — PictureEssenceProcessingSubDescriptor
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

#ifndef MXFPP_PICTURE_ESSENCE_PROCESSING_SUBDESCRIPTOR_BASE_H_
#define MXFPP_PICTURE_ESSENCE_PROCESSING_SUBDESCRIPTOR_BASE_H_

#include <libMXF++/metadata/SubDescriptor.h>

namespace mxfpp
{

class PictureEssenceProcessingSubDescriptorBase : public SubDescriptor
{
public:
    friend class MetadataSetFactory<PictureEssenceProcessingSubDescriptorBase>;
    static const mxfKey setKey;

public:
    PictureEssenceProcessingSubDescriptorBase(HeaderMetadata *headerMetadata);
    virtual ~PictureEssenceProcessingSubDescriptorBase();

    // getters
    mxfAUID getImageProcessingModel() const;
    mxfAUID getColorimetricDataSetIdentifier() const;
    bool haveFlip() const;
    uint8_t getFlip() const;
    bool haveFlop() const;
    uint8_t getFlop() const;

    // setters
    void setImageProcessingModel(mxfAUID value);
    void setColorimetricDataSetIdentifier(mxfAUID value);
    void setFlip(uint8_t value);
    void setFlop(uint8_t value);

protected:
    PictureEssenceProcessingSubDescriptorBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
