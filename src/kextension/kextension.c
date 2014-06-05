#include <webkit2/webkit-web-extension.h>


/*   http://blogs.igalia.com/carlosgc/2013/09/10/webkit2gtk-web-process-extensions/ */


/*
 * epiphany/lib/ephy-web-dom-utils.c Copyright © 2013 Igalia S.L. . Original code GPLV2+, here GPLV3+
 */
/*
gboolean
k2000_has_modified_forms (WebKitDOMDocument *document)
{
  gulong forms_n;
  int i;

  forms = webkit_dom_document_get_forms (document);
  forms_n = webkit_dom_html_collection_get_length (forms);

  for (i = 0; i < forms_n; i++) {
    WebKitDOMHTMLCollection *elements;
    WebKitDOMNode *form_element = webkit_dom_html_collection_item (forms, i);
    gulong elements_n;
    int j;
    gboolean modified_input_element = FALSE;

    elements = webkit_dom_html_form_element_get_elements (WEBKIT_DOM_HTML_FORM_ELEMENT (form_element));
    elements_n = webkit_dom_html_collection_get_length (elements);

    for (j = 0; j < elements_n; j++) {
      WebKitDOMNode *element;

      element = webkit_dom_html_collection_item (elements, j);

      if (WEBKIT_DOM_IS_HTML_TEXT_AREA_ELEMENT (element))
        if (webkit_dom_html_text_area_element_is_edited (WEBKIT_DOM_HTML_TEXT_AREA_ELEMENT (element)))
          return TRUE;

}
*/

static void
web_page_created_callback (WebKitWebExtension *extension,
                           WebKitWebPage      *web_page,
                           gpointer            user_data)
{
  WebKitDOMDocument *document;
  gchar             *title;

  document = webkit_web_page_get_dom_document (web_page);
  title = webkit_dom_document_get_title (document);
  g_print ("Page %d created for %s with title %s\n",
           webkit_web_page_get_id (web_page),
           webkit_web_page_get_uri (web_page),
           title);
  g_free (title);
}


/* Keep this name as is */
G_MODULE_EXPORT void
webkit_web_extension_initialize (WebKitWebExtension *extension)
{
  g_signal_connect (extension, "page-created",
                    G_CALLBACK (web_page_created_callback),
                    NULL);
  g_warning ("web extension initialize");
}
