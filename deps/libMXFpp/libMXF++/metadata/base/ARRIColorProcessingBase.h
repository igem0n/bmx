/*
 * ARRI RDD 55 §6.2.4.6 — ColorProcessing Set
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

#ifndef MXFPP_ARRI_COLOR_PROCESSING_BASE_H_
#define MXFPP_ARRI_COLOR_PROCESSING_BASE_H_

#include <libMXF++/metadata/InterchangeObject.h>

namespace mxfpp
{

class ARRIColorProcessingBase : public InterchangeObject
{
public:
    friend class MetadataSetFactory<ARRIColorProcessingBase>;
    static const mxfKey setKey;

public:
    ARRIColorProcessingBase(HeaderMetadata *headerMetadata);
    virtual ~ARRIColorProcessingBase();

    // getters
    bool getWhiteBalanceApplied() const;
    MetadataSet* getSceneColorEncoding() const;
    bool haveColorLookApplied() const;
    bool getColorLookApplied() const;
    bool haveLUT3Ds() const;
    std::vector<MetadataSet*> getLUT3Ds() const;
    bool haveLookModified() const;
    bool getLookModified() const;
    bool haveCDLSlope() const;
    std::vector<float> getCDLSlope() const;
    bool haveCDLOffset() const;
    std::vector<float> getCDLOffset() const;
    bool haveCDLPower() const;
    std::vector<float> getCDLPower() const;
    bool haveCDLSaturation() const;
    float getCDLSaturation() const;
    bool haveLookIntensity() const;
    float getLookIntensity() const;
    bool haveLookFileName() const;
    std::string getLookFileName() const;
    bool haveLookNote() const;
    std::string getLookNote() const;
    bool haveVideoRenderingVersion() const;
    std::string getVideoRenderingVersion() const;

    // setters
    void setWhiteBalanceApplied(bool value);
    void setSceneColorEncoding(MetadataSet *value);
    void setColorLookApplied(bool value);
    void setLUT3Ds(const std::vector<MetadataSet*> &value);
    void setLookModified(bool value);
    void setCDLSlope(const std::vector<float> &value);
    void setCDLOffset(const std::vector<float> &value);
    void setCDLPower(const std::vector<float> &value);
    void setCDLSaturation(float value);
    void setLookIntensity(float value);
    void setLookFileName(std::string value);
    void setLookNote(std::string value);
    void setVideoRenderingVersion(std::string value);

protected:
    ARRIColorProcessingBase(HeaderMetadata *headerMetadata, ::MXFMetadataSet *cMetadataSet);
};

};

#endif
