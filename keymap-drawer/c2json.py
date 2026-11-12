import re, json, sys
src = open(sys.argv[1]).read()
names = {"_QWERTY":0,"_LOWER":1,"_RAISE":2,"_ADJUST":3}
layers = []
for body in re.findall(r'=\s*LAYOUT\((.*?)\n\s*\)', src, re.S):
    body = body.replace('\\', ' ')
    keys = [k.strip() for k in re.split(r',(?![^()]*\))', body) if k.strip()]
    keys = [ {"_______":"KC_TRNS","XXXXXXX":"KC_NO"}.get(k,k) for k in keys]
    keys = [re.sub(r'MO\((_\w+)\)', lambda m: f"MO({names[m.group(1)]})", k) for k in keys]
    assert len(keys)==58, len(keys)
    layers.append(keys)
print(json.dumps({"keyboard":"lily58/rev1","keymap":"amurani","layout":"LAYOUT","layers":layers}))
