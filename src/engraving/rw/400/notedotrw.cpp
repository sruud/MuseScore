/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "notedotrw.h"

#include "../../libmscore/notedot.h"

#include "../xmlreader.h"

#include "engravingitemrw.h"

using namespace mu::engraving;
using namespace mu::engraving::rw400;

void NoteDotRW::read(NoteDot* d, XmlReader& e, ReadContext& ctx)
{
    while (e.readNextStartElement()) {
        if (e.name() == "name") {      // obsolete
            e.readText();
        } else if (e.name() == "subtype") {     // obsolete
            e.readText();
        } else if (!EngravingItemRW::readProperties(d, e, ctx)) {
            e.unknown();
        }
    }
}