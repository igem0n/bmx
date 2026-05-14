/*
 * ARRI RDD 55 §6.2.3.3 — TextureGen2ProcessingSubDescriptor
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

#ifndef MXFPP_TEXTURE_GEN2_PROCESSING_SUBDESCRIPTOR_H_
#define MXFPP_TEXTURE_GEN2_PROCESSING_SUBDESCRIPTOR_H_

#include <libMXF++/metadata/base/TextureGen2ProcessingSubDescriptorBase.h>

namespace mxfpp
{

class TextureGen2ProcessingSubDescriptor : public TextureGen2ProcessingSubDescriptorBase
{
public:
    friend class MetadataSetFactory<TextureGen2ProcessingSubDescriptor>;

public:
    TextureGen2ProcessingSubDescriptor(HeaderMetadata *headerMetadata);
    virtual ~TextureGen2ProcessingSubDescriptor();

protected:
    TextureGen2ProcessingSubDescriptor(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
