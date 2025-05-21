/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2020 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __RECCONTROLLEROUTPUT_H_F7BDA585__
#define __RECCONTROLLEROUTPUT_H_F7BDA585__

#include <ProcessorHeaders.h>


namespace RecControllerOutputNamespace {

    /**
        Controls the outputs of the Open Ephys Acquisition Board

        Only works if an Acquisition Board plugin is in the signal chain

        @see GenericProcessor
     */
    class RecControllerOutput : public GenericProcessor
    {
    public:

        /** Constructor*/
        RecControllerOutput();

        /** Destructor*/
        ~RecControllerOutput() { }

        /** Registers the parameters*/
        void registerParameters() override;

        /** Searches for events and triggers the Arduino output when appropriate. */
        void process(AudioBuffer<float>& buffer) override;

        /** Convenient interface for responding to incoming events. */
        void handleTTLEvent(TTLEventPtr event) override;

        /** Creates the RecControllerOutputEditor. */
        AudioProcessorEditor* createEditor() override;

        /** Manually triggers output when editor button is clicked */
        void triggerOutput();

        /** Responds to change in parameter trigger value */
        void parameterValueChanged(Parameter*);

    private:

        bool gateIsOpen;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RecControllerOutput);
    };

}


#endif  // __RECCONTROLLEROUTPUT_H_F7BDA585__
