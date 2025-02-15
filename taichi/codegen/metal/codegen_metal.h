#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "taichi/inc/constants.h"
#include "taichi/lang_util.h"
#include "taichi/program/program.h"
#include "taichi/runtime/metal/data_types.h"
#include "taichi/runtime/metal/kernel_manager.h"
#include "taichi/runtime/metal/kernel_utils.h"
#include "taichi/codegen/metal/struct_metal.h"

namespace taichi {
namespace lang {
namespace metal {

CompiledKernelData run_codegen(
    const CompiledRuntimeModule *compiled_runtime_module,
    const std::vector<CompiledStructs> &compiled_snode_trees,
    Kernel *kernel,
    PrintStringTable *print_strtab,
    OffloadedStmt *offloaded);

// If |offloaded| is nullptr, this compiles the AST in |kernel|. Otherwise it
// compiles just |offloaded|. These ASTs must have already been lowered at the
// CHI level.
FunctionType compile_to_metal_executable(
    Kernel *kernel,
    KernelManager *kernel_mgr,
    const CompiledRuntimeModule *compiled_runtime_module,
    const std::vector<CompiledStructs> &compiled_snode_trees,
    OffloadedStmt *offloaded = nullptr);

}  // namespace metal
}  // namespace lang
}  // namespace taichi
