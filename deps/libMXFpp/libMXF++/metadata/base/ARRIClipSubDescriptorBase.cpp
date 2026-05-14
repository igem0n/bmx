/*
 * ARRI RDD 55 §6.2.4.1 — ClipSubDescriptor Set
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


const mxfKey ARRIClipSubDescriptorBase::setKey = MXF_SET_K(ClipSubDescriptor);


ARRIClipSubDescriptorBase::ARRIClipSubDescriptorBase(HeaderMetadata *headerMetadata)
: SubDescriptor(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ARRIClipSubDescriptorBase::ARRIClipSubDescriptorBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: SubDescriptor(headerMetadata, cMetadataSet)
{}

ARRIClipSubDescriptorBase::~ARRIClipSubDescriptorBase()
{}


MetadataSet* ARRIClipSubDescriptorBase::getImageSensorCharacteristics() const
{
    return getStrongRefItem(&MXF_ITEM_K(ClipSubDescriptor, ImageSensorCharacteristics));
}

MetadataSet* ARRIClipSubDescriptorBase::getClipColorProcessing() const
{
    return getStrongRefItem(&MXF_ITEM_K(ClipSubDescriptor, ClipColorProcessing));
}

bool ARRIClipSubDescriptorBase::haveImageChecksumType() const
{
    return haveItem(&MXF_ITEM_K(ClipSubDescriptor, ImageChecksumType));
}

mxfAUID ARRIClipSubDescriptorBase::getImageChecksumType() const
{
    return getAUIDItem(&MXF_ITEM_K(ClipSubDescriptor, ImageChecksumType));
}


void ARRIClipSubDescriptorBase::setImageSensorCharacteristics(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(ClipSubDescriptor, ImageSensorCharacteristics), value);
}

void ARRIClipSubDescriptorBase::setClipColorProcessing(MetadataSet *value)
{
    setStrongRefItem(&MXF_ITEM_K(ClipSubDescriptor, ClipColorProcessing), value);
}

void ARRIClipSubDescriptorBase::setImageChecksumType(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(ClipSubDescriptor, ImageChecksumType), value);
}
