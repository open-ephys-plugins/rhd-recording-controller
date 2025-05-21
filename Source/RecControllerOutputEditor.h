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

#ifndef __RECCONTROLLEROUTPUTEDITOR_H_28EB4CC9__
#define __RECCONTROLLEROUTPUTEDITOR_H_28EB4CC9__


#include <EditorHeaders.h>

namespace RecControllerOutputNamespace {

    /**

      User interface for the RecControllerOutput processor.

      @see RecControllerOutput

    */

    class RecControllerOutput;

    class RecControllerOutputEditor : public GenericEditor,
                                 public Button::Listener

    {
    public:

        /** Constructor*/
        RecControllerOutputEditor(GenericProcessor* parentNode);

        /** Destructor*/
        ~RecControllerOutputEditor() { }

        /** Responds to trigger button press*/
        void buttonClicked(Button* button);

    private:

        std::unique_ptr<UtilityButton> triggerButton;

        RecControllerOutput* board;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RecControllerOutputEditor);

    };


}

#endif  // __RECCONTROLLEROUTPUTEDITOR_H_28EB4CC9__
