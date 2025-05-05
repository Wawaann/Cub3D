/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:04:56 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/05 10:55:03 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

#define MINIAUDIO_IMPLEMENTATION
#define MA_NO_PULSEAUDIO
#include "../lib/include/miniaudio.h"

t_audio	*init_sound(ma_engine *engine, char *asset, float vol)
{
	char	*file;
	t_audio	*audio;

	file = ft_strjoin("./assets/audio/", asset);
	audio = ft_calloc(1, sizeof(t_audio));
	audio->sound = ft_calloc(1, sizeof(ma_sound));
	ma_sound_init_from_file(engine, file, MA_SOUND_FLAG_STREAM, NULL, NULL,
		audio->sound);
	ma_sound_set_volume(audio->sound, vol);
	audio->use = false;
	audio->playing = false;
	free(file);
	return (audio);
}

void	play_sound(t_audio *audio)
{
	if (!audio->playing)
	{
		ma_sound_start(audio->sound);
		audio->playing = true;
	}
	if (!ma_sound_is_playing(audio->sound))
	{
		audio->use = false;
		audio->playing = false;
	}
}

void	handle_audio(t_data *game)
{
	if (game->sound[0]->use)
		play_sound(game->sound[0]);
	if (game->sound[1]->use)
		play_sound(game->sound[1]);
	if (game->sound[2]->use)
		play_sound(game->sound[2]);
	if (game->sound[3]->use)
		play_sound(game->sound[3]);
}
