#ifndef __ZXSTRING_H
#define __ZXSTRING_H


UINTN
EFIAPI
zx_strlen (
  IN      CONST CHAR8               *String
  );



CHAR8 *
EFIAPI
zx_strcpy (
  OUT     CHAR8                     *Destination,
  IN      CONST CHAR8               *Source
  );



INTN
EFIAPI
zx_strcmp (
  IN      CONST CHAR8               *FirstString,
  IN      CONST CHAR8               *SecondString
  );




#endif

