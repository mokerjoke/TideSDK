/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#ifndef _TI_MEDIA_GST_SOUND_H_
#define _TI_MEDIA_GST_SOUND_H_

#include <tide/tide.h>
#include <vector>

using namespace tide;

namespace ti
{
    class GstSound;
    typedef AutoPtr<GstSound> SharedGstSound;

    class GstSound : public Sound
    {
    public:
        GstSound(std::string& url);
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

    private:
        GstElement* pipeline;
        guint watchEventSourceId;
        std::string fileURL;
    };
}

#endif
