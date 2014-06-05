/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * k2000.c
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

#include <webkit2/webkit2.h>

#include "k2000.h"




G_DEFINE_TYPE (K2000, k2000, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro K2000_APPLICATION gets K2000 - DO NOT REMOVE */





/* Webkit Web View */
static GtkWidget *
k2000_new_view ()
{
   gchar *html = "<html><body contentEditable='true'>Toto</body></html>";
   WebKitWebView *v;

  v = webkit_web_view_new ();
  webkit_web_view_load_html (v, html, NULL);
    return v;
}


/* Create a new window loading a file */
static void
k2000_new_window (GApplication *app,
                           GFile        *file)
{
    GtkWidget *window, *view;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "K2000");

    view = k2000_new_view ();
    gtk_container_add (GTK_CONTAINER (window), view);
    
	
    gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
    if (file != NULL)
    {
        /* TODO: Add code here to open the file in the new window */
    }

    gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
k2000_activate (GApplication *application)
{
    k2000_new_window (application, NULL);
}

static void
k2000_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
    gint i;

    for (i = 0; i < n_files; i++)
        k2000_new_window (application, files[i]);
}

static void
k2000_init (K2000 *object)
{
}

static void
k2000_finalize (GObject *object)
{
    G_OBJECT_CLASS (k2000_parent_class)->finalize (object);
}

static void
k2000_class_init (K2000Class *klass)
{
    G_APPLICATION_CLASS (klass)->activate = k2000_activate;
    G_APPLICATION_CLASS (klass)->open = k2000_open;

    G_OBJECT_CLASS (klass)->finalize = k2000_finalize;
}

K2000 *
k2000_new (void)
{
    return g_object_new (k2000_get_type (),
                         "application-id", "org.gnome.k2000",
                         "flags", G_APPLICATION_HANDLES_OPEN,
                         NULL);
}

