/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2014 Open Ephys

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

#ifndef __CHANNELCANVAS_H_2AD3C591__
#define __CHANNELCANVAS_H_2AD3C591__

#include <VisualizerEditorHeaders.h>

#include "ChannelComponent.h"
#include "ChannelList.h"

namespace RhythmNode
{

class DeviceThread;

/**

	  Allows the user to edit channel metadata
	  and check electrode impedance values.

	  @see SourceNode

	  */

class ChannelCanvas : public Visualizer
{
public:
    /** Constructor */
    ChannelCanvas (DeviceThread* board,
                   DeviceEditor* editor);

    /** Destructor */
    ~ChannelCanvas() {}

    /** Render the background */
    void paint (Graphics& g) override;

    /** Sets the layout of sub-components*/
    void resized() override;

    /** Called when the component's tab becomes visible again*/
    void refreshState() override;

    /** Called when parameters of the underlying data processor are changed*/
    void updateSettings() override;

    /** Calls update after a delay*/
    void updateAsync();

    /** Called instead of repaint to avoid redrawing underlying components*/
    void refresh() override;

    /** Called when data acquisition starts*/
    void beginAnimation() override;

    /** Called when data acquisition ends*/
    void endAnimation() override;

    /** Child components*/
    std::unique_ptr<Viewport> channelViewport;
    std::unique_ptr<ChannelList> channelList;

    /** Pointer to the acquisition device */
    DeviceThread* board;

    /** Pointer to the editor object*/
    DeviceEditor* editor;
};

} // namespace RhythmNode
#endif // __CHANNELCANVAS_H_2AD3C591__
