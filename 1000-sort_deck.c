#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * struct deck_node_s - Doubly-linked list node for a card deck
 *
 * @card: Pointer to the card (a string)
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/**
 * card_t - Typedef for struct card_s
 */
typedef struct card_s card_t;

/**
 * struct card_s - Structure representing a card
 *
 * @value: Value of the card (0-13, with 0 representing "King" for a joker card)
 * @kind: Kind of the card (One of "SPADE", "HEART", "CLUB", "DIAMOND")
 */
struct card_s
{
    const char *value;
    const char *kind;
};

/**
 * sort_deck - Sorts a deck of cards
 *
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL)
        return;

    size_t deck_size = 0;
    deck_node_t *current = *deck;

    // Calculate the size of the deck
    while (current)
    {
        deck_size++;
        current = current->next;
    }

    // Convert the deck to an array for sorting
    card_t **card_array = malloc(sizeof(card_t *) * deck_size);
    if (card_array == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    current = *deck;
    for (size_t i = 0; i < deck_size; i++)
    {
        card_array[i] = current->card;
        current = current->next;
    }

    // Use the qsort function to sort the card array
    qsort(card_array, deck_size, sizeof(card_t *), compare_cards);

    // Update the deck with the sorted cards
    current = *deck;
    for (size_t i = 0; i < deck_size; i++)
    {
        current->card = card_array[i];
        current = current->next;
    }

    free(card_array);
}

/**
 * compare_cards - Comparison function for qsort
 *
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if card1
 *         is found, respectively, to be less than, to match, or be greater
 *         than card2.
 */
int compare_cards(const void *card1, const void *card2)
{
    card_t *c1 = *(card_t **)card1;
    card_t *c2 = *(card_t **)card2;

    // Compare values first
    int value_diff = get_card_value(c1) - get_card_value(c2);

    if (value_diff == 0)
    {
        // If values are equal, compare kinds
        return get_kind_index(c1->kind) - get_kind_index(c2->kind);
    }

    return value_diff;
}

/**
 * get_card_value - Gets the numeric value of a card
 *
 * @card: Pointer to the card
 * Return: Numeric value of the card
 */
int get_card_value(const card_t *card)
{
    // Implement logic to convert the card's value to a numeric value
    // For example, you can map "King", "Queen", "Jack", etc., to numeric values
}

/**
 * get_kind_index - Gets the index of the card kind in a predefined order
 *
 * @kind: Pointer to the kind string
 * Return: Index of the kind in the predefined order
 */
int get_kind_index(const char *kind)
{
    // Implement logic to assign an index to each kind in a predefined order
    // For example, you can use an array {"SPADE", "HEART", "CLUB", "DIAMOND"}
}
