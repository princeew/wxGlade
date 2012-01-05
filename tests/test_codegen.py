"""
@copyright: 2012 Carsten Grohmann

@license: MIT (see license.txt) - THIS PROGRAM COMES WITH NO WARRANTY
"""

# import test base class
from tests import WXGladeBaseTest

# import project modules
import common
from xml_parse import CodeWriter

class TestCodeGen(WXGladeBaseTest):
    """\
    Test code generation
    """

    def generateCode(self, language, document, filename):
        """\
        Generate code for the given language.

        @param language: Language to generate code for
        @param document: XML document to generate code for
        @type document:  String
        @param filename: Name of the virtual output file
        @type filename:  String
        """
        self.failUnless(
            language in common.code_writers,
            "No codewriter loaded for %s" % language
            )

        # generate code
        CodeWriter(
            writer=common.code_writers[language],
            input=document,
            from_string=True,
            out_path=filename,
            )

        return

    def test_Lisp_quote_path(self):
        """\
        Test codegen.lisp_codegen.quote_path()
        
        @see: L{wxglade.codegen.lisp_codegen.quote_path()}
        """
        quote_path = common.code_writers['lisp'].quote_path
        examples = [
            ('icon.png',                 '"icon.png"'),
            ('/usr',                     '"/usr"'),
            ('/usr/shar/icons/iso.png',  '"/usr/shar/icons/iso.png"'),
            (r'C:\Temp',                r'"C:\\Temp"'),
            ('/tmp/wx""glade',          r'"/tmp/wx\"\"glade"'),
            ]
        for unquoted, tquoted in examples:
            aquoted = quote_path(unquoted)
            self.assertEqual(
                aquoted,
                tquoted,
                "Lisp quotation for '%s' returned '%s' expected '%s'" % (
                    unquoted,
                    aquoted,
                    tquoted,
                    )
                )

    def test_Lisp_wxBitmapButton(self):
        """\
        Test Lisp code generation with small wxBitmapButton example

        @see: L{wxglade.widgets.bitmap_button.lisp_codegen}
        """
        source = self.loadFile('Lisp_wxBitmapButton', '.wxg')
        result = self.loadFile('Lisp_wxBitmapButton', '.lisp')

        # generate Lisp code
        self.generateCode('lisp', source, 'Lisp_wxBitmapButton.lisp')
        generated = self.vFiles['Lisp_wxBitmapButton.lisp'].getvalue()

        # compare source files
        delta = self.diff(result, generated)

        self.failIf(
            delta,
            "Generated source file and expected result differs:\n%s" % delta,
            )
