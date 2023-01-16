/*
 *  XMail by Davide Libenzi (Intranet and Internet mail server)
 *  Copyright (C) 1999,..,2010  Davide Libenzi
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Davide Libenzi <davidel@xmailserver.org>
 *
 */

#ifndef _USRMAILLIST_H
#define _USRMAILLIST_H

#define INVALID_USRML_HANDLE        ((USRML_HANDLE) 0)

#define DEFAULT_MLUSER_PERMS        "RW"

struct MLUserInfo {
	char *pszAddress;
	char *pszPerms;
};

typedef struct USRML_HANDLE_struct {
} *USRML_HANDLE;

MLUserInfo *UsrMLAllocDefault(char const *pszAddress, char const *pszPerms);
int UsrMLFreeUser(MLUserInfo * pMLUI);
int UsrMLCheckUserPost(UserInfoBean * pUI, char const *pszUser, char const *pszLogonUser);
int UsrMLAddUser(UserInfoBean * pUI, MLUserInfo const *pMLUI);
int UsrMLRemoveUser(UserInfoBean * pUI, const char *pszMLUser);
int UsrMLGetUsersFileSnapShot(UserInfoBean * pUI, const char *pszFileName);
USRML_HANDLE UsrMLOpenDB(UserInfoBean * pUI);
void UsrMLCloseDB(USRML_HANDLE hUsersDB);
MLUserInfo *UsrMLGetFirstUser(USRML_HANDLE hUsersDB);
MLUserInfo *UsrMLGetNextUser(USRML_HANDLE hUsersDB);

#endif
