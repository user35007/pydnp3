/*
 * -*- coding: utf-8 -*- {{{
 * vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
 *
 * Copyright 2018, Kisensum.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Neither Kisensum, nor any of its employees, nor any jurisdiction or
 * organization that has cooperated in the development of these materials,
 * makes any warranty, express or implied, or assumes any legal liability
 * or responsibility for the accuracy, completeness, or usefulness or any
 * information, apparatus, product, software, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 * Reference herein to any specific commercial product, process, or service
 * by trade name, trademark, manufacturer, or otherwise does not necessarily
 * constitute or imply its endorsement, recommendation, or favoring by Kisensum.
 * }}}
 */

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/IChannelCallbacks.h>

namespace py = pybind11;
using namespace std;

namespace asiopal
{
/**
* Overriding virtual functions from interface class IChannelCallbacks.
*/
    struct PyIChannelCallbacks : public IChannelCallbacks
    {
    public:
        /* Inherit the constructors */
        using IChannelCallbacks::IChannelCallbacks;

        /* Trampoline for IChannelCallbacks virtual functions */
        void OnReadComplete(const std::error_code& ec, size_t num) override {
            PYBIND11_OVERLOAD_PURE (
                void,
                IChannelCallbacks,
                OnReadComplete,
                ec, num
            );
        }
        void OnWriteComplete(const std::error_code& ec, size_t num) override {
            PYBIND11_OVERLOAD_PURE (
                void,
                IChannelCallbacks,
                OnWriteComplete,
                ec, num
            );
        }
    };
}

void bind_IChannelCallbacks(py::module &m)
{
    // ----- struct: asiopal::IChannelCallbacks -----
    py::class_<asiopal::IChannelCallbacks, asiopal::PyIChannelCallbacks>(m, "IChannelCallbacks")

        .def(py::init<>())

        .def(
            "OnReadComplete",
            &asiopal::IChannelCallbacks::OnReadComplete,
            py::arg("ec"), py::arg("num")
        )

        .def(
            "OnWriteComplete",
            &asiopal::IChannelCallbacks::OnReadComplete,
            py::arg("ec"), py::arg("num")
        );
}
