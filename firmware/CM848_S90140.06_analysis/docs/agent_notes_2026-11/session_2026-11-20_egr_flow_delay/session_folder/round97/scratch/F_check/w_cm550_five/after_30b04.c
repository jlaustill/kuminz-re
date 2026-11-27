//

/* An empty interrupt handler: it saves d0 / d1 / a0 / a1, restores them and returns with RTE.
   Nothing in the dumped ROM (0x0-0x3ffff) installs or calls it: there is no absolute, PC-relative
   or table reference to 0x30b04. Four identical stubs without function rows sit at 0x19ca0,
   0x1a1d6, 0x1a73c and 0x1a950, also unreferenced (was cm550_protectionLimitValueInit, which the
   body does not support). (was cm550_protectionLimitValueInit; PR #53 round 97) */

void cm550_emptyInterruptHandler(void)

{
  return;
}



//
