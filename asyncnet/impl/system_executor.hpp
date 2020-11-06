//
// Created by lince on 11/6/20.
//

#ifndef ASYNCNET_IMPL_SYSTEM_EXECUTOR_HPP
#define ASYNCNET_IMPL_SYSTEM_EXECUTOR_HPP

#include <asyncnet/system_executor.hpp>
#include <asyncnet/system_context.hpp>

namespace asyncnet {

    template<typename Function, typename ProtoAllocator>
    void system_executor::post(Function &&f, const ProtoAllocator &a) {
        context()._work_io_context.get_executor().post(std::forward<Function>(f), a);
    }

    template<typename Function, typename ProtoAllocator>
    void system_executor::dispatch(Function &&f, const ProtoAllocator &a) {
        context()._work_io_context.get_executor().dispatch(std::forward<Function>(f), a);
    }
}

#endif //ASYNCNET_IMPL_SYSTEM_EXECUTOR_HPP