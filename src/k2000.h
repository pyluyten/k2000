/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * k2000.h
 * Copyright (C) 2014 Pierre-Yves Luyten <py@luyten.fr>
 * 
 * K2000 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * K2000 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _K2000_
#define _K2000_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define K2000_TYPE_APPLICATION             (k2000_get_type ())
#define K2000_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), K2000_TYPE_APPLICATION, K2000))
#define K2000_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), K2000_TYPE_APPLICATION, K2000Class))
#define K2000_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), K2000_TYPE_APPLICATION))
#define K2000_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), K2000_TYPE_APPLICATION))
#define K2000_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), K2000_TYPE_APPLICATION, K2000Class))

typedef struct _K2000Class K2000Class;
typedef struct _K2000 K2000;


struct _K2000Class
{
    GtkApplicationClass parent_class;
};

struct _K2000
{
    GtkApplication parent_instance;

};

GType k2000_get_type (void) G_GNUC_CONST;
K2000 *k2000_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

