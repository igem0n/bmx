/*
 * ARRI RDD 55 §6.2.4.4 — ColorEncoding Set
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


const mxfKey ARRIColorEncodingBase::setKey = MXF_SET_K(ColorEncoding);


ARRIColorEncodingBase::ARRIColorEncodingBase(HeaderMetadata *headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

ARRIColorEncodingBase::ARRIColorEncodingBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

ARRIColorEncodingBase::~ARRIColorEncodingBase()
{}


mxfAUID ARRIColorEncodingBase::getColorEncodingPrimariesAndWhitePoint() const
{
    return getAUIDItem(&MXF_ITEM_K(ColorEncoding, ColorEncodingPrimariesAndWhitePoint));
}

mxfAUID ARRIColorEncodingBase::getColorEncodingTransferFunction() const
{
    return getAUIDItem(&MXF_ITEM_K(ColorEncoding, ColorEncodingTransferFunction));
}


void ARRIColorEncodingBase::setColorEncodingPrimariesAndWhitePoint(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(ColorEncoding, ColorEncodingPrimariesAndWhitePoint), value);
}

void ARRIColorEncodingBase::setColorEncodingTransferFunction(mxfAUID value)
{
    setAUIDItem(&MXF_ITEM_K(ColorEncoding, ColorEncodingTransferFunction), value);
}
