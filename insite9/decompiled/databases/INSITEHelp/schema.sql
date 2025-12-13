-- ----------------------------------------------------------
-- MDB Tools - A library for reading MS Access database files
-- Copyright (C) 2000-2011 Brian Bruns and others.
-- Files in libmdb are licensed under LGPL and the utilities under
-- the GPL, see COPYING.LIB and COPYING files respectively.
-- Check out http://mdbtools.sourceforge.net
-- ----------------------------------------------------------

-- That file uses encoding UTF-8

CREATE TABLE [FaultHelpFileMap]
 (
	[SystemType]			Long Integer NOT NULL, 
	[EFCode]			Long Integer NOT NULL, 
	[Language]			Text (50) NOT NULL, 
	[HelpFile]			Text (50) NOT NULL
);

CREATE TABLE [HelpFileMap]
 (
	[ModuleID]			Long Integer NOT NULL, 
	[Language]			Text (50) NOT NULL, 
	[HelpFile]			Text (50) NOT NULL
);

CREATE TABLE [HelpTopicMap]
 (
	[ContextID]			Text (255) NOT NULL, 
	[ModuleID]			Long Integer NOT NULL, 
	[HelpPage]			Text (255) NOT NULL, 
	[Comment]			Text (255)
);

CREATE TABLE [LanguagePrefixes]
 (
	[Language]			Text (50), 
	[Prefix]			Text (50)
);


