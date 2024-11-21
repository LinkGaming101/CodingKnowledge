from random import randint

class Actor:
    def __init__(self, level, attack, defense, health, armor_class):
        self.level = level
        self.attack = attack
        self.defense = defense
        self.health = health
        self.armor_class = armor_class

    def attack_action(self):
        #grab the target of the attack and then decrease health of target if hit
        print('Attacking!')
    
    def defend_action(self):
        #grab the defenders defense and then if hit subtract the amount of defense from the attack damage
        print('Defending!')


class Player(Actor):
    def __init__(self, level, attack, defense, health, armor_class, name):
        super().__init__(level, attack, defense, health, armor_class)
        self.name = name
    
    def __repr__(self):
        return ('<Player: {} at level {}>'
                .format(self.name,
                        self.level))
    
    #player specific world actions

    def inspect_action(self):
        #grab a stat block of the target
        print('inspecting item...')

    def move_action(self):
        #moves the player in a specific direction
        print('moving in the direction!')

    #player specific combat actions

    def info_action(self):
        #grab a stat block of the target
        print('researching enemy...')

    def run_action(self):
        #grab the target of the attack and then decrease health of target if hit
        print('running away!')
    
class Enemy(Actor):
    def __init__(self, level, attack, defense, health, armor_class, kind):
        super().__init__(level, attack, defense, health, armor_class)
        self.kind = kind
    
    def __repr__(self):
        return ('<Enemy: level {} {}>'
                .format(self.level,
                        self.kind))
    
    def statblock(self):
        return('''
            <-------+=+=+=+=+=+=+------->
            | {} Level {}               |
            | AC: {}                    |
            | HP: {} , Defense: {}      |
            | Attack: {}                |
            <-------+=+=+=+=+=+=+------->
        '''.format(self.kind, self.level, self.armor_class, 
                   self.health, self.defense, self.attack))
    