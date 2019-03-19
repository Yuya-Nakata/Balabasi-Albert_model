int network[t_num][t_num] ={0};
                int link_num[t_num] ={0}; //各端末の接続数
								for(int i =0; i < start_num; i++){
									link_num[i] = start_num - 1;
								}

                int seikousuu = 0;	//新規ノードが繋がったかを確認する変数 nodeが100こなら97で全て繋がったことが確認できる
                bool nukenasi = true; 	//どのノードとも繋がらなかったらループ

                //初期状態をリンクさせる

								//m0 = 2
								if(start_num == 2){
                makelink(network,0,1); distance[0][1] = 1; distance[1][0] = 1;
							}

								//m0 = 3
								else if(start_num == 3){
                makelink(network,0,1); distance[0][1] = 1; distance[1][0] = 1;
                makelink(network,1,2); distance[1][2] = 1; distance[2][1] = 1;
                makelink(network,2,0); distance[2][0] = 1; distance[0][2] = 1;
							}

								//m0 = 4
								else if(start_num == 4){
                makelink(network,0,1); distance[0][1] = 1; distance[1][0] = 1;
                makelink(network,0,2); distance[0][2] = 1; distance[2][0] = 1;
                makelink(network,0,3); distance[0][3] = 1; distance[3][0] = 1;
								makelink(network,1,2); distance[1][2] = 1; distance[2][1] = 1;
                makelink(network,1,3); distance[1][3] = 1; distance[3][1] = 1;
                makelink(network,2,3); distance[2][3] = 1; distance[3][2] = 1;
							}

								//m0 = 5
								else if(start_num == 5){
                makelink(network,0,1); distance[0][1] = 1; distance[1][0] = 1;
                makelink(network,0,2); distance[0][2] = 1; distance[2][0] = 1;
                makelink(network,0,3); distance[0][3] = 1; distance[3][0] = 1;
								makelink(network,0,4); distance[0][4] = 1; distance[4][0] = 1;
                makelink(network,1,2); distance[1][2] = 1; distance[2][1] = 1;
								makelink(network,1,3); distance[1][3] = 1; distance[3][1] = 1;
                makelink(network,1,4); distance[1][4] = 1; distance[4][1] = 1;
                makelink(network,2,3); distance[2][3] = 1; distance[3][2] = 1;
								makelink(network,2,4); distance[2][4] = 1; distance[4][2] = 1;
								makelink(network,3,4); distance[3][4] = 1; distance[4][3] = 1;
							}

							else {
								cout << "初期ノード数が定義外" << endl;
								exit(0);
							}

                for(int i = start_num; i < t_num; i++){

                    nukenasi = true;
                    while(nukenasi){
                        for(int j = 0; j < i; j++){
                            double R;
                            R=(double)(rand()) /RAND_MAX; //0~1のランダムな値を生成
                            double zz;
                            zz = (double)link_num[j] / network_edge_num;
                            R = R-zz;

                                if(R < 0){
                                    makelink(network,j,i);
																		distance[i][j] = 1;
																		distance[j][i] = 1;
                                    network_edge_num += 2;
                                    link_num[j]++;
                                    link_num[i]++;
                                    seikousuu++;
                                    //cout << seikousuu << endl;
                                    nukenasi = false;
                                    break;
                                }
                        }
                    }
                }
