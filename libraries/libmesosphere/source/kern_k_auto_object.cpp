/*
 * Copyright (c) Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <mesosphere.hpp>

namespace ams::kern {

    KAutoObject *KAutoObject::Create(KAutoObject *obj) {
        obj->m_ref_count = 1;

        #if defined(MESOSPHERE_ENABLE_DEVIRTUALIZED_DYNAMIC_CAST)
        obj->m_class_token = obj->GetTypeObj().GetClassToken();
        #endif

        return obj;
    }

}
