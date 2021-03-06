#include "idris_opts.h"
#include "idris_rts.h"
// The default options should give satisfactory results under many circumstances.
RTSOpts opts = {
    .init_heap_size = 4096000,
    .max_stack_size = 4096000,
    .show_summary   = 0
};

void idris_main() {
    terminal_initialize();
    terminal_writestring("idris_main");
    VM* vm = init_vm(opts.max_stack_size, opts.init_heap_size, 1);
    initNullaries();
    terminal_writestring("initNullaries complete.");

    _idris__123_runMain0_125_(vm, NULL);

#ifdef IDRIS_DEBUG
    if (opts.show_summary) {
        idris_gcInfo(vm, 1);
    }
#endif
    while(1);
    terminate(vm);

    freeNullaries();
}
