all:
					@make -C repo_checker all
					@cp repo_checker/checker ./
					@make -C repo_push_swap all
					@cp repo_push_swap/push_swap ./

clean:
					@make clean -C repo_checker/
					@make clean -C repo_push_swap/

fclean:
					@make fclean -C repo_checker/
					@make fclean -C repo_push_swap/
					@rm checker
					@rm push_swap

re:					fclean all

.PHONY: 			all clean fclean re