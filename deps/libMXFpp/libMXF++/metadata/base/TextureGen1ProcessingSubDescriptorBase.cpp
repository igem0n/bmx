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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libMXF++/MXF.h>

#include <mxf/mxf_arri.h>

using namespace std;
using namespace mxfpp;


const mxfKey TextureGen1ProcessingSubDescriptorBase::setKey = MXF_SET_K(TextureGen1ProcessingSubDescriptor);


TextureGen1ProcessingSubDescriptorBase::TextureGen1ProcessingSubDescriptorBase(HeaderMetadata *headerMetadata)
: TextureProcessingSubDescriptorBase(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

TextureGen1ProcessingSubDescriptorBase::TextureGen1ProcessingSubDescriptorBase(
    HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: TextureProcessingSubDescriptorBase(headerMetadata, cMetadataSet)
{}

TextureGen1ProcessingSubDescriptorBase::~TextureGen1ProcessingSubDescriptorBase()
{}


uint8_t TextureGen1ProcessingSubDescriptorBase::getTextureNoiseReductionMode() const
{
    return getUInt8Item(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureNoiseReductionMode));
}

float TextureGen1ProcessingSubDescriptorBase::getTextureImageSharpness() const
{
    return getFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureImageSharpness));
}

float TextureGen1ProcessingSubDescriptorBase::getTextureImageDetail() const
{
    return getFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureImageDetail));
}

bool TextureGen1ProcessingSubDescriptorBase::haveTextureNoiseReductionStrength() const
{
    return haveItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureNoiseReductionStrength));
}

float TextureGen1ProcessingSubDescriptorBase::getTextureNoiseReductionStrength() const
{
    return getFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureNoiseReductionStrength));
}


void TextureGen1ProcessingSubDescriptorBase::setTextureNoiseReductionMode(uint8_t value)
{
    setUInt8Item(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureNoiseReductionMode), value);
}

void TextureGen1ProcessingSubDescriptorBase::setTextureImageSharpness(float value)
{
    setFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureImageSharpness), value);
}

void TextureGen1ProcessingSubDescriptorBase::setTextureImageDetail(float value)
{
    setFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureImageDetail), value);
}

void TextureGen1ProcessingSubDescriptorBase::setTextureNoiseReductionStrength(float value)
{
    setFloatItem(&MXF_ITEM_K(TextureGen1ProcessingSubDescriptor, TextureNoiseReductionStrength), value);
}
