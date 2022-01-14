import pygame
import sys
from pygame.locals import *
import random

WIDTH = 1500
HEIGHT = 700
FPS = 700
QUAD_WIDTH = WIDTH/4
MID_HEIGHT = HEIGHT/2

pygame.init()
pygame.font.init()
screenwindow = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Mock Dice Game')

Newicon = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\New112.png')
pygame.display.set_icon(Newicon)

tite_font = pygame.font.SysFont('arial', 70)
tite_label = tite_font.render("Roll The Dice", True,(255,0,0))

dicea = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice1.png')
diceb = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice2.png')
dicec = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice3.png')
diced = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice4.png')
dicee = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice5.png')
dicef = pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Dice6.png')
list1 = [None, dicea, diceb, dicec, diced, dicee, dicef]
bgside = pygame.transform.scale(pygame.image.load(r'C:\Users\91965\OneDrive\Desktop\Mockproject\Paint.png'),(WIDTH, HEIGHT))

def Diceroll():
    player1 = random.randint(1,6)
    player2 = random.randint(1,6)
    
    return player1, player2
 
running       = True
player_face   = None
player1 = 0
player2_face = None
player2 = 0
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_y:
                player1, player2 = Diceroll()
                player_face   = list1[player1]
                player2_face = list1[player2]
                
                if player2 > player1:
                    print(f"Player2 Rolls High. Rolled a {player2}")
                elif player2 < player1:
                    print(f"Player1 Rolls High Rolled a {player1}")
                elif player2 == player1:
                    print("tied!")
    screenwindow.blit( bgside, (0, 0))
    screenwindow.blit(tite_label, (WIDTH//2 - tite_label.get_width()//2, 250))
    if ( player_face != None ):
        screenwindow.blit( player_face, ( QUAD_WIDTH, MID_HEIGHT ) )
    if ( player2_face != None ):
        screenwindow.blit( player2_face, ( 3*QUAD_WIDTH, MID_HEIGHT ) )
    pygame.display.flip()
pygame.quit()