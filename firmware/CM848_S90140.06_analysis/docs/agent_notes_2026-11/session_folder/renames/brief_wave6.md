# Wave 6 addendum (read after brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md)

Your leads are earlier agents' leftover notes and uncertain rows. Read them in FULL from the aligned results files named
in your task (one JSON object per line; take the rows whose "kind" is "note", or whose "verdict" is "uncertain") - the
copies in task 042 are cut short. Five waves have renamed ~190 functions and ~830 globals (comments end `(was <old>)`);
look a name up with `grep '(was <name>)'` when it no longer exists, and never re-propose a rename that is done.
firmware/CLAUDE.md "Rename waves 1-5" summarises what the code turned out to be. Same result kinds as wave 5. About 80
tool calls. Skip a lead with a one-line note when it is only informational or still cannot be settled.
