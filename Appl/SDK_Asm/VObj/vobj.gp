##############################################################################
#
#	Copyright (c) Geoworks 1990-1994 -- All Rights Reserved
#
# PROJECT:	GEOS
# MODULE:	VObj (Sample GEOS application)
# FILE:		vobj.gp
#
# AUTHOR:	John Wedgwood, 1/93
#
# DESCRIPTION:	This file contains Geode definitions for the "VObj" sample
#		application. This file is read by the GLUE linker to
#		build this application.
#
# RCS STAMP:
#	$Id: vobj.gp,v 1.1 97/04/04 16:33:58 newdeal Exp $
#
##############################################################################
#
# Permanent name: is required by Glue to set the permanent name and extension
# of the geode. The permanent name of a library is what goes in the imported
# library table of a geode (along with the protocol number). It is also
# what Swat uses to name the patient.
#
name vobj.app

#
# Long filename: this name can displayed by geoManager, and is used to identify
# the application for inter-application communication.
#
longname "VObj"

#
# Specify geode type: is an application, will have its own process (thread),
# and is multi-launchable.
#
type	appl, process

#
# Specify class name for application process. Methods sent to the Application's
# process will be handled by the ItemProcessClass, which is defined
# in item.asm.
#
class	VObjProcessClass

#
# Specify application object. This is the object in the .ui file which serves
# as the top-level UI object in the application. See vobj.ui.
#
appobj	VObjApp

#
# Token: this four-letter name is used by geoManager to locate the icon for this
# application in the database.
#
tokenchars "SAMP"
tokenid 8

#
# Libraries: list which libraries are used by the application.
#
library	geos
library	ui

#
# Code Resources: these are all read-only and sharable by multiple instances
# of this application.
#
resource CommonCode		code read-only shared
#
# Resources: list all resource blocks which are used by the application.
# (standard discardable code resources do not need to be mentioned).
#
resource AppResource	ui-object
resource Interface	ui-object

#
# Notice that the AppInterface resource runs objects under the application
# thread, and therefore is not of type "ui-object".
#
resource AppInterface	object

#
# Must export the classes...
#
export	VObjContentClass
export	VObjClass
