#!/usr/bin/python3

COLORS = ['Red', 'Orange', 'Yellow', 'Green', 'Cyan', 'Blue', 'Magenta', 'Purple', 'White', 'Black', 'Gray', 'Silver', 'Pink', 'Maroon', 'Brown', 'Beige', 'Tan', 'Peach', 'Lime', 'Olive', 'Turquoise', 'Teal', 'NavyBlue', 'Indigo', 'Violet']
CREATURES= ['Spinach', 'Zebra', 'Bulbul', 'Capsicum', 'Neem', 'Rhinoceros', 'Lemon', 'Deer', 'Leopard', 'Cotton', 'Potato', 'MoneyPlant', 'Turmeric', 'SunBear', 'Goat', 'Drumstick', 'Earthworm', 'Mint', 'Cheetah', 'Watermelon', 'Gaur', 'Cobra', 'Pineapple', 'Onion', 'Lion', 'Dog', 'RhesusMonkey', 'Blackbuck', 'Curryplant', 'Cucumber', 'Pig', 'Clove', 'SiberianCrane', 'Parrot', 'HouseSparrow', 'Bat', 'Snakehead', 'WildAss', 'GreenGram', 'Tulsi', 'HouseMouse', 'Giraffe', 'Mango', 'Guava', 'HoneyBee', 'Eagle', 'Camel', 'Wolf', 'Cockroach', 'Jowar', 'Monkey', 'Garlic', 'Carrot', 'Apple', 'Nilgai', 'GavialOrGharial', 'Prawn', 'Koel', 'RedFox', 'BlackGram', 'Ant', 'Horse', 'Banyan', 'Starfish', 'Butterfly', 'Bear', 'Lettuce', 'Alpaca', 'BlackPepper', 'Coriander', 'Elephant', 'Hippopotamus', 'Spider', 'HouseCrow', 'Henna', 'Banana', 'Fish', 'Maize', 'Panther', 'Cat', 'Bamboo', 'PolarBear', 'Pigeon', 'GreatHornedOwl', 'Wheat', 'HorseGram', 'Orange', 'Bird', 'Cow', 'WildBoar', 'Ginger', 'Sheep', 'Chinkara', 'Hen', 'Radish', 'Buffalo', 'Sandalwood', 'Sparrow', 'Hangul', 'Tomato', 'Peacock', 'Albatross', 'CommonMyna', 'Dolphin', 'Brinjal', 'Tiger', 'HouseWallLizard', 'Tobacco', 'Housefly', 'RedGram', 'Rabbit']

import sys, random
random.seed(1)

def _FetchColor():
    return COLORS[  random.randint(0, len(COLORS)-1)  ]

def _FetchCreature():
    return CREATURES[  random.randint(0, len(CREATURES)-1)  ]

def _GenerateKeyValue():
    color, creature, serial = _FetchColor(), _FetchCreature(), str(random.randint(100, 199))[1:]
    key = '{}-{}-{}'.format(color, creature, serial)

    value = '{},{}'.format(  str(random.randint(1000, 1999))[1:], str(random.randint(1000, 1999))[1:]  )
    value = color[0] + creature[0] + '_' + value

    return key, value

def _GenerateKeyValuePairs(N):
    r = {}
    for i in range(N):
        k, v = _GenerateKeyValue()
        if k not in r:
            r[k] = v

    return r

def generateKeyValuePairs(N):
    return _GenerateKeyValuePairs(N)

if __name__ == '__main__':
    try:
        d = _GenerateKeyValuePairs(10)
    except KeyboardInterrupt:
        sys.exit(0)

    for k in d:
        print(  '{} {}'.format(k, d[k])  )
