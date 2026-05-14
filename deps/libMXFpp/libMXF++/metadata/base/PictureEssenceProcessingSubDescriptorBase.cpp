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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <libMXF++/MXF.h>

#include <mxf/mxf_arri.h>

using namespace std;
using namespace mxfpp;


const mxfKey PictureEssenceProcessingSubDescriptorBase::setKey = MXF_SET_K(PictureEssenceProcessingSubDescriptor);


PictureEssenceProcessingSubDescriptorBase::PictureEssenceProcessingSubDescriptorBase(HeaderMetadata *headerMetadata)
: SubDescriptor(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

PictureEssenceProcessingSubDescriptorBase::PictureEssenceProcessingSubDescriptorBase(
    HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: SubDescriptor(headerMetadata, cMetadataSet)
{}

PictureEssenceProcessingSubDescriptorBase::~PictureEssenceProcessingSubDescriptorBase()
{}


mxfAUID PictureEssenceProcessingSubDescriptorBase::getImageProcessingModel() const
{
    return getAUIDItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, ImageProcessingModel));
}

mxfAUID PictureEssenceProcessingSubDescriptorBase::getColorimetricDataSetIdentifier() const
{
    return getAUIDItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, ColorimetricDataSetIdentifier));
}

bool PictureEssenceProcessingSubDescriptorBase::haveFlip() const
{
    return haveItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flip));
}

uint8_t PictureEssenceProcessingSubDescriptorBase::getFlip() const
{
    return getUInt8Item(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flip));
}

bool PictureEssenceProcessingSubDescriptorBase::haveFlop() const
{
    return haveItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flop));
}

uint8_t PictureEssenceProcessingSubDescriptorBase::getFlop() const
{
    return getUInt8Item(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flop));
}


void PictureEssenceProcessingSubDescriptorBase::setImageProcessingModel(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, ImageProcessingModel), value);
}

void PictureEssenceProcessingSubDescriptorBase::setColorimetricDataSetIdentifier(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, ColorimetricDataSetIdentifier), value);
}

void PictureEssenceProcessingSubDescriptorBase::setFlip(uint8_t value)
{
    setUInt8Item(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flip), value);
}

void PictureEssenceProcessingSubDescriptorBase::setFlop(uint8_t value)
{
    setUInt8Item(&MXF_ITEM_K(PictureEssenceProcessingSubDescriptor, Flop), value);
}
