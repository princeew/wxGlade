# ChoicesProperty.py: defines a Property and two handlers used by choice,
# combo_box, radio_box, list_box
#
# Copyright (c) 2002 Alberto Griggio <albgrig@tiscalinet.it>
# License: GPL (see license.txt)

import widget_properties

class ChoicesProperty(widget_properties.GridProperty):
    def write(self, outfile, tabs):
        from xml.sax.saxutils import escape
        write = outfile.write
        write('    ' * tabs + '<choices>\n')
        tab_s = '    ' * (tabs+1)
        for val in self.get_value():
            v = widget_properties._encode(val[0])
            write('%s<choice>%s</choice>\n' % (tab_s, escape(v)))
        write('    ' * tabs + '</choices>\n')

# end of class ChoicesProperty


class ChoicesHandler:
    def __init__(self, owner):
        self.choices = []
        self.curr_choice = []
        self.owner = owner
    def start_elem(self, name, attrs):
        pass
    def end_elem(self, name):
        if name == 'choice':
            self.choices.append(["".join(self.curr_choice)])
            self.curr_choice = []
        elif name == 'choices':
            self.owner.set_choices(self.choices)
            self.owner.properties['choices'].set_value(
                self.owner.get_choices())
            self.choices = []
            return True # remove the handler
    def char_data(self, data):
        self.curr_choice.append(data)

# end of class ChoicesHandler

class ChoicesCodeHandler:
    """\
    handler for the 'choices' property of various elements
    """
    def __init__(self):
        self.choices = []
        self.curr_choice = []
        
    def start_elem(self, name, attrs): pass
            
    def end_elem(self, name, code_obj):
        if name == 'choice':
            c = "".join(self.curr_choice)
            self.choices.append("".join(self.curr_choice))
            self.curr_choice = []
        elif name == 'choices':
            code_obj.properties['choices'] = self.choices
            return True

    def char_data(self, data):
        self.curr_choice.append(data)

# end of class ChoicesCodeHandler
