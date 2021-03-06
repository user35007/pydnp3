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

#include <opendnp3/gen/DoubleBitBinaryQuality.h>

namespace py = pybind11;
using namespace std;

void bind_DoubleBitBinaryQuality(py::module &m)
{
    // ----- enum class: opendnp3::DoubleBitBinaryQuality -----
    py::enum_<opendnp3::DoubleBitBinaryQuality>(m, "DoubleBitBinaryQuality",
        "Quality field bitmask for double bit binary values.")

        .value(
            "ONLINE",
            opendnp3::DoubleBitBinaryQuality::ONLINE,
            "Set when the data is good, meaning that rest of the system can trust the value."
        )

		.value(
		    "RESTART",
		    opendnp3::DoubleBitBinaryQuality::RESTART,
		    "The quality all points get before we have established communication (or populated) the point."
		)

		.value(
		    "COMM_LOST",
		    opendnp3::DoubleBitBinaryQuality::COMM_LOST,
		    "Set if communication has been lost with the source of the data (after establishing contact)."
		)

		.value(
		    "REMOTE_FORCED",
		    opendnp3::DoubleBitBinaryQuality::REMOTE_FORCED,
		    "Set if the value is being forced to a fake value somewhere in the system."
		)

		.value(
		    "LOCAL_FORCED",
		    opendnp3::DoubleBitBinaryQuality::LOCAL_FORCED,
		    "Set if the value is being forced to a fake value on the original device."
		)

		.value(
		    "CHATTER_FILTER",
		    opendnp3::DoubleBitBinaryQuality::CHATTER_FILTER,
		    "Set if the value is oscillating very quickly and some events are being suppressed."
		)

		.value(
		    "STATE1",
		    opendnp3::DoubleBitBinaryQuality::STATE1,
		    "State bit 1."
		)

		.value(
		    "STATE2",
		    opendnp3::DoubleBitBinaryQuality::STATE2,
		    "State bit 2."
		);
}
