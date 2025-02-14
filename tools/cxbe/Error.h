// ******************************************************************
// *
// *  This file is part of Cxbe
// *
// *  This program is free software; you can redistribute it and/or
// *  modify it under the terms of the GNU General Public License
// *  as published by the Free Software Foundation; either version 2
// *  of the License, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have received a copy of the GNU General Public License
// *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#ifndef ERROR_H
#define ERROR_H

#include "Cxbx.h"

// inherit from this class for handy error reporting capability
class Error
{
    public:
        // return current error (zero if there is none)
        const char *GetError() const { return m_szError; }

        // is the current error fatal? (class is "dead" on fatal errors)
        bool IsFatal() const { return m_bFatal; }

        // clear the current error (returns false if error was fatal)
        bool ClearError();

    protected:
        // protected constructor so this class must be inherited from
        Error() : m_szError(0), m_bFatal(false) { }

        // protected deconstructor
       ~Error() { delete[] m_szError; }

        // protected so only derived class may set an error
        void SetError(const char *x_szError, bool x_bFatal);

    private:
        // current error information
        bool  m_bFatal;
        char *m_szError;
};

#endif
