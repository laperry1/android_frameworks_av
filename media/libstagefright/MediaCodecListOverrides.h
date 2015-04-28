/*
 * Copyright 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MEDIA_CODEC_LIST_OVERRIDES_H_

#define MEDIA_CODEC_LIST_OVERRIDES_H_

#include <media/MediaCodecInfo.h>
#include <media/stagefright/foundation/AString.h>

#include <utils/StrongPointer.h>
#include <utils/KeyedVector.h>

namespace android {

struct MediaCodecInfo;

bool splitString(const AString &s, const AString &delimiter, AString *s1, AString *s2);

bool splitString(
        const AString &s, const AString &delimiter, AString *s1, AString *s2, AString *s3);

void profileCodecs(
        const Vector<sp<MediaCodecInfo>> &infos,
        KeyedVector<AString, CodecSettings> *results,
        bool forceToMeasure = false);  // forceToMeasure is mainly for testing

void applyCodecSettings(
        const AString& codecInfo,
        const CodecSettings &settings,
        Vector<sp<MediaCodecInfo>> *infos);

void exportResultsToXML(const char *fileName, const KeyedVector<AString, CodecSettings>& results);

}  // namespace android

#endif  // MEDIA_CODEC_LIST_OVERRIDES_H_