#include "shell.h"

/**
 * _myenv -> prints current enviroment
 * @info: structure containing arguments, maintain
 * constant function prototype,
 * Return: 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv -> gets value of an environ variable
 * @info: Structure contains arguments, used to maintain
 * @name: env var name
 *
 * Return: Value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}

	return (NULL);
}

/**
 * _mysetenv -> Initialize a new variable
 * or modify an existing one
 * @info: structure containing potential arguments, used to maintain
 * constant function prototype
 * Return: 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 1)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * populate_env_list -> Populates env listed list
 * @info: Structure containing arguments, used to maintain
 * constant function prototype,
 * Return: 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 1; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

