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

#include <asiopal/Synchronized.h>

namespace py = pybind11;
using namespace std;

template <class T>
void declareSynchronized(py::module &m, string const & type)
{
    // ----- class: asiopal::Synchronized<T> -----
    py::class_<asiopal::Synchronized<T>>(m, ("Synchronized" + type).c_str(),
        "Provides thread-safe access to a value that can be set once.")

        .def(py::init<>())

        .def(
            "WaitForValue",
            &asiopal::Synchronized<T>::WaitForValue
        )

        .def(
            "SetValue",
            &asiopal::Synchronized<T>::SetValue,
            py::arg("value")
        );
}

void bind_Synchronized(py::module &m)
{
}
